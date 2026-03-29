#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    struct Item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}


void fractionalKnapsack(struct Item items[], int n, int W) {
    float x[n]; 
    int weight = 0;
    float totalValue = 0.0;


    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }


    sortItems(items, n);


    for (int i = 0; i < n; i++) {
        if (weight + items[i].weight <= W) {
            x[i] = 1.0;
            weight += items[i].weight;
            totalValue += items[i].value;
        } else {
            x[i] = (float)(W - weight) / items[i].weight;
            totalValue += x[i] * items[i].value;
            weight = W;
            break;
        }
    }


    printf("Fractions of items taken:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }

    printf("Maximum Value: %.2f\n", totalValue);
}


int main() {
    int n = 3;
    int W = 50;

    struct Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };


    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    fractionalKnapsack(items, n, W);

    return 0;
}

