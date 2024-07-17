#include <stdio.h>

void main() {
    int n;
    float m;
    printf("Enter the capacity\n");
    scanf("%f", &m);

    printf("Enter the number of objects\n");
    scanf("%d", &n);

    printf("Enter the elements of Profit/ Weight of %d objects\n", n);
    float w[n], p[n], x[n];
    float ratio[n];
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &p[i], &w[i]);
        x[i] = 0;
        ratio[i] = p[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap profits
                float tp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = tp;

                // Swap weights
                float tw = w[j + 1];
                w[j + 1] = w[j];
                w[j] = tw;

                // Swap ratios
                float tr = ratio[j + 1];
                ratio[j + 1] = ratio[j];
                ratio[j] = tr;
            }
        }
    }

    float rc = m;
    float mp = 0;
    for (int i = 0; i < n; i++) {
        // If weight is less than remaining capacity 
        if (w[i] <= rc) {
            // make it visited
            x[i] = 1;
            // Subtract weight from remaining capacity
            rc -= w[i];
            // Add to total Profit
            mp += p[i];
        }
        // If weight is greater than capacity 
        else {
            // Take portion of remaining capacity
            x[i] = rc / w[i];
            // add to profit
            mp += x[i] * p[i];
            break; // No more capacity left
        }
    }

    printf("The Selected objects are:\n");
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            printf("Object %d (fraction: %.2f)\n", i + 1, x[i]);
        }
    }

    printf("The Maximum Profit is: %.2f\n", mp);
}
