import { Component, signal, Input } from '@angular/core';

@Component({
  selector: 'app-greeting',
  imports: [],
  templateUrl: './greeting.html',
  styleUrls: ['./greeting.scss']
})
export class Greeting {
  @Input() message: string = 'Hello hello!';
}
