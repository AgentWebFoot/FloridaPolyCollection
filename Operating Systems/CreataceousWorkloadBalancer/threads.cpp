#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

struct ThreadData {
	char id;
	int work;
	int semaphoreCount;
	vector<int> requiredSemaphores;
};

sem_t semaphores[3];

vector<int> getRandomSemaphores(int count) {
	vector<int> indices = {0, 1, 2};
	random_shuffle(indices.begin(), indices.end());
	return vector<int>(indices.begin(), indices.begin()+ count);
}

void* threadFunction(void* arg) {
	ThreadData* data = static_cast<ThreadData*>(arg);

	while (data->work > 0) {

		if (data->requiredSemaphores.empty()) {
			data->semaphoreCount = rand() % 3 + 1;
			data->requiredSemaphores = getRandomSemaphores(data->semaphoreCount);
		}

		bool acquired = true;
		vector<int> acquiredSemaphores;
		for (int semIdx: data->requiredSemaphores) {
			if (sem_trywait(&semaphores[semIdx]) == 0){
				acquiredSemaphores.push_back(semIdx);
			}
			else {
				acquired = false;
				break;
			}
		}

		if (!acquired) {
			for (int semIdx : acquiredSemaphores) {
				sem_post(&semaphores[semIdx]);
			}
			continue;
		}


		--data->work;
		for (int semIdx : data->requiredSemaphores) {
			cout << data->id << " < " << semIdx << "\n";
		}

		cout << data->id << " has " << data->work << " left\n";

		for (int semIdx : data->requiredSemaphores) {
			cout << data->id << " > " << semIdx << "\n";
			sem_post(&semaphores[semIdx]);
		}

		struct timespec ts;
		ts.tv_sec = 0;
		ts.tv_nsec = (rand() % 11) * 1000000;
//		nanosleep(&ts, NULL);

		data->requiredSemaphores.clear();
	}
	pthread_exit(NULL);
}

int main() {
	const int threadCount = 5;
	pthread_t threads[threadCount];
	ThreadData threadData[threadCount];

	srand(time(NULL));

	for (int i = 0; i < 3; i++) {
		sem_init(&semaphores[i], 0, 1);
	}

	for (int i = 0; i < threadCount; ++i) {
		threadData[i].id = 'A' + i;
		threadData[i].work = 10;
		threadData[i].semaphoreCount = 0;
		threadData[i].requiredSemaphores.clear();

		if (pthread_create(&threads[i], NULL, threadFunction, &threadData[i]) != 0) {
			perror("Failed to create thread");
			return 1;
		}
	}

	for (int i = 0; i < threadCount; ++i) {
		pthread_join(threads[i], NULL);
	}

	for (int i = 0; i < 3; ++i) {
		sem_destroy(&semaphores[i]);
	}

	cout << "All threads have finished \n";

	return 0;
}
