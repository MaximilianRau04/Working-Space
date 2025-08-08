import { Component, signal } from '@angular/core';
import { Greeting } from '../components/greeting/greeting';
import { Counter } from '../components/counter/counter';

@Component({
  selector: 'app-home',
  imports: [Greeting, Counter],
  templateUrl: './home.html',
  styleUrls: ['./home.scss']
})
export class Home {
  homeMessage = "Hello World!";

  keyUpHandler(event: KeyboardEvent) {
    console.log(`Key ${event.key} pressed!`);
  }
}
