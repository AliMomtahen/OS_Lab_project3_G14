int change_param_of_all(float priority_ratio, float arrival_time_ratio, 
    float executed_cycles_ratio , float process_size_ratio)
{
  acquire(&ptable.lock);
  struct proc* p;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    p->sched_info.bjf.priority_ratio = priority_ratio;
    p->sched_info.bjf.arrival_time_ratio = arrival_time_ratio;
    p->sched_info.bjf.executed_cycle_ratio = executed_cycles_ratio;
    p->sched_info.bjf.process_size_ratio = process_size_ratio;
  }
  release(&ptable.lock);
  return -1;
}


int change_param_proc(int pid, float priority_ratio, float arrival_time_ratio, 
    float executed_cycles_ratio , float process_size_ratio)
{
  acquire(&ptable.lock);
  struct proc* p;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    if(p->pid == pid){
      p->sched_info.bjf.priority_ratio = priority_ratio;
      p->sched_info.bjf.arrival_time_ratio = arrival_time_ratio;
      p->sched_info.bjf.executed_cycle_ratio = executed_cycles_ratio;
      p->sched_info.bjf.process_size_ratio = process_size_ratio;
      
      release(&ptable.lock);
      return 0;
    }
  }
  release(&ptable.lock);
  return -1;
}


int find_digit_number(int x){
  int y=0;
  while (x)
  {
     x = x / 10;
     y++;
  }
  return y;
  
}

void print_info(){
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



