#include <stdio.h>

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int visited[f + 1];
    for (int i = 1; i <= f; i++) {
        visited[i] = 0;
    }

    int queue[f + 1];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    int button_pushes = 0;
    int move_up[] = {u, -d};

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int current = queue[front++];

            if (current == g) {
                printf("%d\n", button_pushes);
                return 0;
            }

            for (int j = 0; j < 2; j++) {
                int next = current + move_up[j];

                if (next >= 1 && next <= f && !visited[next]) {
                    visited[next] = 1;
                    queue[rear++] = next;
                }
            }
        }

        button_pushes++;
    }

    printf("use the stairs\n");

    return 0;
}
