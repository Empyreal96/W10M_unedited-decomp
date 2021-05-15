// PopPepTriggerActivity 
 
int __fastcall PopPepTriggerActivity(int a1, int a2, int a3, int a4)
{
  int *v8; // r2
  int v9; // r3

  PopPepCancelActivities();
  PopPepVerifyActivities(a1, a2, a3);
  if ( a2 )
    v8 = *(int **)(a2 + 4 * a3 + 48);
  else
    v8 = *(int **)(a1 + 4 * a3 + 48);
  v9 = *v8;
  v8[1] = a4;
  *v8 = v9 | 1;
  return (*(int (__fastcall **)(int, int, int))&ActivityAttributes[124 * a3 + 112])(a1, a2, a4);
}
