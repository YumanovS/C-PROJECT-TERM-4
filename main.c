#include <stdio.h>

void ff(){
    float a[4][4] = {{1,0.17,-0.25,0.54},{0.47,1,0.67,-0.32},{-0.11,0.35,1,-0.74},{0.55,0.43,0.36,1}};
    float f[4][1] = {{0.3},{0.5},{0.7},{0.9}};
    float x[4][1] = {{0},{0},{0},{0}};
    for (int i = 0;i<=3;i++) {
        for (int j = 0; j <= 3; j++) {
            if (i != j){
                a[i][j] = a[i][j] / ((-1)*a[i][i]);
            }

        }

    }
    for (int i = 0; i <= 3; i++){
        x[i][0] = f[i][0] / a[i][i];

    }

    for (int i = 0; i <= 3; i++){
        f[i][0] = f[i][0] / a[i][i];

    }
    for (int i = 0; i <= 3; i++){
        a[i][i] = 0;
    }
    float t = 0;
    for (int k = 0;k <= 16;k++){
        for (int i = 0;i<=3;i++) {
            for (int j = 0; j <= 3; j++) {
                t += (a[i][j] * x[j][0]);
            }

            x[i][0] = t + f[i][0];
            t = 0;
        }
    }
    for (int i = 0;i<=3;i++) {
        printf("%f ",x[i][0]);

        printf("%s","\n");
    }


}



void main(){
    ff();
};
