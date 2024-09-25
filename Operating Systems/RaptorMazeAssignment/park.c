#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/random.h>

#define BUFFER_SIZE 1024
#define SIZE 21

#define PROC_NAME "park"

char* generateMaze(void);

ssize_t read(struct file *file, char *buf, size_t count, loff_t *pos);

// File operations structure
static struct file_operations ops = {
    	.owner = THIS_MODULE,
    	.read = read,
};

/*
Name: Elijah Garmon
Date: 9/22/24
Description: Initializes Module
*/
int init(void) {
    	proc_create(PROC_NAME, 0, NULL, &ops);
    	printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
    	return 0;
}

/*
Name: Elijah Garmon
Date: 9/22/24
Description: Deletes module
*/
void pleaseExit(void) {
    	// Removes the /proc/park entry
    	remove_proc_entry(PROC_NAME, NULL);
    	printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

/*
Name: Elijah Garmon
Date: 9/24/24
Description: Creates the maze
*/
char* generateMaze(void) {
    	char *grid_str = (char*)kmalloc(BUFFER_SIZE, GFP_KERNEL);
	int index = 0;
    	int i, j;
	int random_start;
	int current_row = 1;
	int current_col;
	int direction;
	int last_move_down = 0;
	int down_twice = 0;

    	for (i = 0; i < SIZE; i++) {
        	for (j = 0; j < SIZE; j++) {
            		if (i % 2 == 0) {
                		index += sprintf(grid_str + index, "#");
            		}
			else {
                		index += sprintf(grid_str + index, (j % 2 == 0) ? "#" : "0");
            		}
        	}
        	index += sprintf(grid_str + index, "\n");
    	}
	do {
		get_random_bytes(&random_start, sizeof(random_start));
		random_start = ((random_start % (SIZE / 2)) * 2)+1;
	} while (grid_str[random_start + SIZE + 1] != '0');

	grid_str[random_start] = ' ';
	current_col = random_start;

	while (current_row < (SIZE - 1)) {
		get_random_bytes(&direction, sizeof(direction));
		if (last_move_down) {
			if (down_twice) {
				direction = direction % 2;
			}
			else {
				direction = direction % 3;
			}
		}
		else{
			direction = direction % 4;
		}

		if (direction == 0 && current_col > 1) {
			current_col -= 1;
			grid_str[current_row * (SIZE + 1) + current_col] = ' ';
			current_col -= 1;
			last_move_down = 0;
			down_twice = 0;
		}
		else if (direction == 1 && current_col < (SIZE - 2)) {
			current_col += 1;
			grid_str[current_row * (SIZE + 1) + current_col] = ' ';
			current_col += 1;
			last_move_down = 0;
			down_twice = 0;
		}
		else if (direction > 1){
			current_row += 1;
			grid_str[current_row * (SIZE + 1) + current_col] = ' ';
			current_row += 1;
			if (last_move_down){
				down_twice = 1;
			}
			last_move_down = 1;
		}

		if (current_row >= (SIZE - 1)) {
			break;
		}

		grid_str[current_row * (SIZE + 1) + current_col] = ' ';
	}

	for (i = 1; i < SIZE - 1; i++) {
		for (j = 1; j < SIZE - 1; j++) {
			while (grid_str[i * (SIZE + 1) + j] == '0') {
				get_random_bytes(&direction, sizeof(direction));
				direction = direction % 4;
				if (direction == 0 && i > 1) {
					grid_str[(i - 1) * (SIZE + 1) + j] = ' ';
					grid_str[i * (SIZE + 1) + j] = ' ';
				}
				else if (direction == 1 && i < SIZE - 2) {
					grid_str[(i + 1) * (SIZE + 1) + j] = ' ';
					grid_str[i * (SIZE + 1) + j] = ' ';
				}
				else if (direction == 2 && j > 1) {
					grid_str[i * (SIZE + 1) + (j - 1)] = ' ';
					grid_str[i * (SIZE + 1) + j] = ' ';
				}
				else if (direction == 3 && j < SIZE - 2) {
					grid_str[i * (SIZE + 1) + (j + 1)] = ' ';
					grid_str[i * (SIZE + 1) +j] = ' ';
				}
			}
		}
	}

    	return grid_str;
}

/*
Name: Elijah Garmon
Date: 9/23/24
Description: Reads and prints module
*/
ssize_t read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
   	int rv = 0;
    	char buffer[BUFFER_SIZE];
    	static int completed = 0;
    	char *grid_str;

    	if (completed) {
        	completed = 0;
        	return 0; // Return 0 to indicate end of file
    	}

 	completed = 1;

    	grid_str = generateMaze();
    	rv = snprintf(buffer, BUFFER_SIZE, "%s", grid_str); // Use snprintf for safety

    	if (copy_to_user(usr_buf, buffer, rv)) {
        	kfree(grid_str);
        	return -EFAULT;
    	}

    	kfree(grid_str);
    	return rv;
}

/* Macros for registering module entry and exit points. */
module_init(init);
module_exit(pleaseExit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("We have a TRex");
MODULE_AUTHOR("Elijah Garmon");
