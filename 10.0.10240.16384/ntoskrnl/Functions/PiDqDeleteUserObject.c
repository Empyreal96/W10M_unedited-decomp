// PiDqDeleteUserObject 
 
int __fastcall PiDqDeleteUserObject(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4)
{
  int v6; // r7
  unsigned __int16 *v7; // r6
  unsigned int v8; // r4
  unsigned int i; // r5
  unsigned __int16 *v10; // r0
  unsigned __int16 *v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[1] = a4;
  v12[0] = 0;
  v6 = PiDqGetRelativeObjectRegPath(a2, a3, v12);
  v7 = v12[0];
  if ( v6 < 0 )
    goto LABEL_11;
  v6 = PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, a1, v12[0]);
  if ( a3 == 1 )
  {
    v8 = 2;
LABEL_7:
    i = 0;
    if ( !v8 )
      goto LABEL_11;
    goto LABEL_8;
  }
  if ( a3 != 3 )
  {
    v8 = 0;
    goto LABEL_7;
  }
  v8 = 1;
  for ( i = 0; i < v8; ++i )
  {
LABEL_8:
    v10 = wcsrchr(v7, 92);
    if ( v10 )
    {
      *v10 = 0;
      if ( PnpCtxRegDeleteKey(PiPnpRtlCtx, a1, v7) < 0 )
        break;
    }
  }
LABEL_11:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v6;
}
