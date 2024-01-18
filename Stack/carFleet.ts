function carFleet(target: number, position: number[], speed: number[]): number {
    let fleets = 1;
    let stack: number[] = [];
    let cars: { position: number; speed: number }[] = position
        .map((start, i) => {
            return { position: start, speed: speed[i] };
        })
        .sort((a, b) => b.position - a.position);

    for (let i = 0; i < cars.length; i++) {
        let distance = (target - cars[i].position) / cars[i].speed;
        if (stack[stack.length - 1] < distance) {
            while (stack[stack.length - 1] < distance) {
                stack.pop();
            }
            fleets++;
        }
        stack.push(distance);
    }
    return fleets;
}
