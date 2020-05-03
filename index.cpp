#include<bangtal.h>
#include <stdio.h> 

SceneID scene1, scene2, scene3, scene4, scene5;

ObjectID problem1, problem2;

ObjectID left[5];
ObjectID right[5];

int leftX[5] = {169, 22};
int rightX[5] = {472, 336};
int Y[5] = {226, 130};
int radius[5] = {20, 100};

bool checkIn(int x, int y, int cx, int cy, int r) {
	return (x > cx - r && x < cx + r && y > cy - r && y < cy + r);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == problem1) {
		if(checkIn(x, y, leftX[0], Y[0], radius[0]) || checkIn(x, y, rightX[0], Y[0], radius[0])) {
			showObject(left[0]);
			showObject(right[0]);
			showMessage("정답입니다!!");
			endGame();
		}
	}
}

int main() {

	setMouseCallback(mouseCallback);

	scene1 = createScene("틀린그림찾기1", "");
	scene2 = createScene("틀린그림찾기2", "");
	scene3 = createScene("틀린그림찾기3", "");
	scene4 = createScene("틀린그림찾기4", "");
	scene5 = createScene("틀린그림찾기5", "");

	problem1 = createObject("images/part1.jpg");
	locateObject(problem1, scene1, 0, 0);
	showObject(problem1); //169 226  472 226

	left[0] = createObject("images/check.png");
	locateObject(left[0], scene1, leftX[0] - radius[0], Y[0] - radius[0]);
	right[0] = createObject("images/check.png");
	locateObject(right[0], scene1, rightX[0] - radius[0], Y[0] - radius[0]);


	/* problem2 = createScene("images/part2.jpg");
	locateObject(problem2, scene2, 0, 0); // 22 336 130
	showObject(problem2); */

	showMessage("좌우에 틀린 곳을 찾아보세요");

	startGame(scene1);
}