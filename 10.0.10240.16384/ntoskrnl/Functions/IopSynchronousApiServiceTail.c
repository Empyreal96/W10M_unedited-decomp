// IopSynchronousApiServiceTail 
 
int __fastcall IopSynchronousApiServiceTail(int a1, unsigned int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  unsigned int v7; // r5
  int v8; // r4
  _DWORD *v9; // r1
  int varg_r0; // [sp+28h] [bp+8h]
  int varg_r2; // [sp+30h] [bp+10h]

  varg_r0 = a1;
  varg_r2 = a3;
  v7 = a2;
  v8 = a1;
  if ( a1 == 259 )
  {
    if ( KeWaitForSingleObject(a2, 0, a4, 0, 0) == 192 )
      IopCancelAlertedRequest(v7, a3);
    v9 = a5;
    v8 = *a5;
  }
  else
  {
    v9 = a5;
  }
  *a6 = *v9;
  a6[1] = v9[1];
  ExFreePoolWithTag(v7);
  return v8;
}
