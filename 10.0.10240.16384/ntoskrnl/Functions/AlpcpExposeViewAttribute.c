// AlpcpExposeViewAttribute 
 
int __fastcall AlpcpExposeViewAttribute(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r2
  int v9; // r6
  int v10; // r5
  bool v11; // zf
  unsigned int *v12; // r2
  int v13; // r4
  int v14; // r0
  int v15; // r4
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r1
  int v19; // r2
  _DWORD v21[8]; // [sp+8h] [bp-20h] BYREF

  v21[0] = a3;
  v21[1] = a4;
  v5 = *(_DWORD *)(a2 + 76);
  if ( !v5 )
    return 0;
  v9 = *(_DWORD *)(v5 + 8);
  v10 = *(_DWORD *)(v9 - 12);
  v11 = v10 == 0;
  if ( v10 <= 0 )
  {
LABEL_10:
    if ( !v11 )
      KeBugCheckEx(24, 0, v9, 32, v10);
  }
  else
  {
    v12 = (unsigned int *)(v9 - 12);
    while ( 1 )
    {
      v13 = v10;
      __dmb(0xBu);
      do
        v14 = __ldrex(v12);
      while ( v14 == v10 && __strex(v10 + 1, v12) );
      v10 = v14;
      __dmb(0xBu);
      if ( v14 == v13 )
        break;
      if ( v14 <= 0 )
      {
        v11 = v14 == 0;
        goto LABEL_10;
      }
    }
  }
  v15 = AlpcpReceiveView(a1, a2, (bool *)v21);
  __dmb(0xBu);
  v16 = (unsigned int *)(v9 - 12);
  do
  {
    v17 = __ldrex(v16);
    v18 = v17 - 1;
  }
  while ( __strex(v18, v16) );
  __dmb(0xBu);
  if ( v18 <= 0 )
  {
    if ( v18 )
      KeBugCheckEx(24, 0, v9, 33, v18);
    AlpcpDestroyBlob(v9);
  }
  if ( v15 >= 0 )
  {
    v19 = *(_DWORD *)(a2 + 76);
    *a3 = 0;
    a3[1] = 0;
    a3[2] = 0;
    a3[3] = 0;
    a3[2] = *(_DWORD *)(v19 + 20);
    a3[3] = *(_DWORD *)(v19 + 24);
    if ( LOBYTE(v21[0]) )
      *a3 = 0x40000;
    *a4 |= 0x40000000u;
    return 0;
  }
  return v15;
}
