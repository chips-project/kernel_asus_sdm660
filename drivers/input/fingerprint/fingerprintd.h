#ifndef __FINGERPRINTD_H
#define __FINGERPRINTD_H
static inline void set_fingerprintd_nice(int nice)
{
	struct task_struct *p;

	read_lock(&tasklist_lock);
	for_each_process(p) {
		if (strstr(p->comm, "erprint"))
			set_user_nice(p, nice);
	}
	read_unlock(&tasklist_lock);
}
#endif
