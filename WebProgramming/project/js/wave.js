import {Point} from './point.js';

export class Wave {
  constructor(color) {
    this.color = color;
    this.points = [];
    this.numberOfPoints = 6;
  }

  resize(stageWidth, stageHeight) {
    this.stageWidth = stageWidth;
    this.stageHeight = stageHeight;
    this.centerX = stageWidth / 2;
    this.centerY = stageHeight / 2;
    this.pointGap = this.stageWidth / (this.numberOfPoints - 1);
    this.init();
  }

  init() {
    for (let i = 0; i < this.numberOfPoints; i++) {
      this.points[i] = new Point(i, this.pointGap * i, this.centerY);
    }
  }

  draw(ctx) {
    ctx.beginPath();

    /* 곡선을 위해 이전의 좌표 기억하기 */
    let prevX = this.points[0].x;
    let prevY = this.points[0].y;

    /* 점의 시작점으로 붓 이동하기 */
    ctx.moveTo(prevX, prevY);

    for (let i = 0; i < this.numberOfPoints; i++) {
      const cx = (prevX + this.points[i].x) / 2;
      const cy = (prevY + this.points[i].y) / 2;

      ctx.quadraticCurveTo(prevX, prevY, cx, cy);
      prevX = this.points[i].x;
      prevY = this.points[i].y;

      /* 공의 위치 변경하기 */
      if (i != 0 && i != this.numberOfPoints - 1) {
        this.points[i].update();
      }
    }
    ctx.lineTo(prevX, prevY);
    ctx.lineTo(this.stageWidth, this.stageHeight);
    ctx.lineTo(0, this.stageHeight);
    ctx.lineTo(this.points[0].x, this.points[0].y);
    ctx.fillStyle = '#0000ff';
    ctx.fill();
    ctx.closePath();
  }
}