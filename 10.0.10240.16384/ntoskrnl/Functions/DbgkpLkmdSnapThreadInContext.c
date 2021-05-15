// DbgkpLkmdSnapThreadInContext 
 
int __fastcall DbgkpLkmdSnapThreadInContext(int *a1, int a2, int *a3)
{
  int v4; // r6
  int result; // r0
  int v8; // r1
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // [sp+8h] [bp-1C0h]
  int v13[110]; // [sp+10h] [bp-1B8h] BYREF

  v4 = 0;
  result = DbgkpLkmdSnapDataEx((int)a1);
  if ( result >= 0 )
  {
    v9 = a3[1];
    *a3 = 0;
    v10 = v9 | 1;
    a3[1] = v10;
    v11 = *a1;
    if ( *a1 )
    {
      v10 = *(_DWORD *)(v11 + 4);
      if ( !v10 )
      {
        *(_DWORD *)(v11 + 4) = a2;
        v10 = v12;
        __dmb(0xBu);
        *(_DWORD *)(v10 + 328) = 0;
        v4 = 1;
      }
    }
    RtlCaptureContext(v13, v8, v11, v10);
    DbgkpLkmdSnapDataEx((int)a1);
    DbgkpLkmdSnapKernelStack((int)a1, a2, v12, v4 == 0, v13, (int)a3);
    result = 0;
  }
  else
  {
    *a3 = result;
  }
  return result;
}
