import { Directive, input, effect, inject, ElementRef } from '@angular/core';


@Directive({
  selector: '[appHighlightCompletedTodo]',
})
export class HighlightCompletedTodo {
  isCompleted = input(false);
  element = inject(ElementRef);

  stylesEffect = effect(() => {
    if (this.isCompleted()) {
      this.element.nativeElement.style.backgroundColor = 'lightgreen';
      this.element.nativeElement.style.border = '1px solid green';
    } else {
      this.element.nativeElement.style.backgroundColor = 'transparent';
      this.element.nativeElement.style.border = 'none';
    }
  });
}
