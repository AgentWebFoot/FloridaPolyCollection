kernel_module = open('/proc/park')

maze = kernel_module.read();
print(maze)

kernel_module.close()
