
void prinfffffft_info(){
  struct proc *p=0;
  cprintf ("PName PID State    Queue Cycle Arrival Priority R_Prty R_Arvl R_Exec R_Size Rank\n");
  cprintf ("--------------------------------------------------------------------------------\n");
  int i=0;
  char *state;
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    if (p->state != UNUSED) {
      switch(p->state){
      case SLEEPING: {
        state = "sleeping";
      }break;
      case RUNNING:{
        state = "running";
      }break;
      case RUNNABLE: {
        state = "runnable";
      }break;
      case ZOMBIE:
        state = "zombie";
      break;
      case EMBRYO: {
        state = "embryo";
      }break;

      default:
        state = "-";
        break;
      }

      cprintf ("%s", p->name);
      for (i = 0; i < 6 - strlen (p->name); i++) {
        cprintf (" ");
      }

      cprintf ("%d", p->pid);
      for (i = 0; i < 4 - find_digit_number(p->pid); i++) {
        cprintf (" ");
      }

      cprintf ("%s", state);
      for (i = 0; i < 9 - strlen (state); i++) {
        cprintf (" ");
      }

      cprintf ("%d", p->sched_info.queue);
      for (i = 0; i < 6 - find_digit_number (p->sched_info.queue); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)p->sched_info.bjf.executed_cycle);
      for (i = 0; i < 6 - find_digit_number ((int)p->sched_info.bjf.executed_cycle); i++) {
        cprintf (" ");
      }

      cprintf ("%d", p->sched_info.bjf.arrival_time);
      for (i = 0; i < 8 - find_digit_number (p->sched_info.bjf.arrival_time); i++) {
        cprintf (" ");
      }

      cprintf ("%d", p->sched_info.bjf.priority);
      for (i = 0; i < 9 - find_digit_number (p->sched_info.bjf.priority); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)p->sched_info.bjf.priority_ratio);
      for (i = 0; i < 7 - find_digit_number ((int)p->sched_info.bjf.priority_ratio); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)p->sched_info.bjf.arrival_time_ratio);
      for (i = 0; i < 7 - find_digit_number ((int)p->sched_info.bjf.arrival_time_ratio); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)p->sched_info.bjf.executed_cycle_ratio);
      for (i = 0; i < 7 - find_digit_number ((int)p->sched_info.bjf.executed_cycle_ratio); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)p->sched_info.bjf.process_size_ratio);
      for (i = 0; i < 7 - find_digit_number ((int)p->sched_info.bjf.process_size_ratio); i++) {
        cprintf (" ");
      }

      cprintf ("%d", (int)bjfrank(p));
      for (i = 0; i < 4 - find_digit_number ((int)bjfrank(p)); i++) {
        cprintf (" ");
      }

      cprintf ("\n");
    }
  }

}



