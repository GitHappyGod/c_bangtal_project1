#include<bangtal.h>
#include <stdio.h> 

SceneID scene0, scene1, scene2, scene3;

ObjectID problem1, problem2, problem3;
ObjectID startButton, endButton, playButton;

ObjectID left[5];
ObjectID right[5];
TimerID timer1;

int leftX[5] = {169, 22, 140};
int rightX[5] = {472, 350, 436};
int Y[5] = {226, 303, 332};
int radius[5] = {20, 50, 30};
bool c1 = false, c2 = false, c3 = false;

bool checkIn(int x, int y, int cx, int cy, int r) {
	return (x > cx - r && x < cx + r && y > cy - r && y < cy + r);
}

void startGame() {
	hideObject(startButton);
	hideObject(endButton);

	showObject(problem1);
	enterScene(scene1);

	startTimer(timer1);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == endButton) {
		endGame();
	}
	else if (object == startButton) {
		startGame();
	}
	else if (object == problem1) {
		if (c1) {
			enterScene(scene2);
		}
		else {
			if (checkIn(x, y, leftX[0], Y[0], radius[0]) || checkIn(x, y, rightX[0], Y[0], radius[0])) {
				showObject(left[0]);
				showObject(right[0]);
				showMessage("정답입니다!! 클릭하면 다음문제로 넘어갑니다.");
				c1 = true;
			}
		}
	}
	else if (object == problem2) {
		printf("%d %d \n", x, y);
		if (c2) {
			enterScene(scene3);
		}
		else {
			if (checkIn(x, y, leftX[1], Y[1], radius[1]) || checkIn(x, y, rightX[1], Y[1], radius[1])) {
				showObject(left[1]);
				showObject(right[1]);
				showMessage("정답입니다!! 클릭하면 다음문제로 넘어갑니다.");
				c2 = true;
			}
		}
	}
	else if (object == problem3) {
		printf("%d %d \n", x, y);
		if (c3) {
			endGame();
		}
		else {
			if (checkIn(x, y, leftX[2], Y[2], radius[2]) || checkIn(x, y, rightX[2], Y[2], radius[2])) {
				showObject(left[2]);
				showObject(right[2]);
				showMessage("정답입니다!! 시간내에 모든 문제를 맞추셨습니다. 클릭하시면 게임이 종료됩니다.");
				c3 = true;
			}
		}
	}
}

void timerCallback(TimerID timer) {
	if (timer1 == timer1) {
		endGame();
	}
}

int main() {

	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);

	scene0 = createScene("틀린그림찾기1", "images/part1.jpg");
	scene1 = createScene("틀린그림찾기1", "");
	scene2 = createScene("틀린그림찾기2", "");
	scene3 = createScene("틀린그림찾기3", "");


	startButton = createObject("images/start.png");
	locateObject(startButton, scene0, 590, 300);
	showObject(startButton);

	endButton = createObject("images/end.png");
	locateObject(endButton, scene0, 590, 250);
	showObject(endButton);

	problem1 = createObject("images/part1.jpg");
	locateObject(problem1, scene1, 0, 0);

	left[0] = createObject("images/check.png");
	locateObject(left[0], scene1, leftX[0] - radius[0], Y[0] - radius[0]);
	right[0] = createObject("images/check.png");
	locateObject(right[0], scene1, rightX[0] - radius[0], Y[0] - radius[0]);


	problem2 = createObject("images/part2.jpg");
	locateObject(problem2, scene2, 0, 0);
	showObject(problem2); // 22 336 130

	left[1] = createObject("images/check.png");
	locateObject(left[1], scene2, leftX[1] - radius[1], Y[1] - radius[1]);
	right[1] = createObject("images/check.png");
	locateObject(right[1], scene2, rightX[1] - radius[1], Y[1] - radius[1]);


	problem3 = createObject("images/part3.jpg");
	locateObject(problem3, scene3, 0, 0);
	showObject(problem3);

	left[2] = createObject("images/check.png");
	locateObject(left[2], scene3, leftX[2] - radius[2], Y[2] - radius[2]);
	right[2] = createObject("images/check.png");
	locateObject(right[2], scene3, rightX[2] - radius[2], Y[2] - radius[2]);

	showMessage("좌우에 틀린 곳을 찾아보세요");

	timer1 = createTimer(30.0f);
	showTimer(timer1);

	startGame(scene0);
}