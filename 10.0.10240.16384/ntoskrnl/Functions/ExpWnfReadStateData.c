// ExpWnfReadStateData 
 
int __fastcall ExpWnfReadStateData(int a1, _DWORD *a2, int a3, unsigned int a4, _DWORD *a5)
{
  int v6; // r9
  unsigned int *v7; // r10
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r5
  int v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  unsigned int *v14; // r4
  unsigned int v15; // r2
  int v17; // [sp+0h] [bp-28h]
  _DWORD *varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  unsigned int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a1;
  v17 = 0;
  v7 = (unsigned int *)(a1 + 48);
  v8 = KeAbPreAcquire(a1 + 48, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_DWORD *)(v6 + 52);
  if ( !v11 )
  {
    *a2 = 0;
LABEL_10:
    *a5 = 0;
    goto LABEL_17;
  }
  if ( v11 == 1 )
  {
    *a2 = *(_DWORD *)(v6 + 56);
    goto LABEL_10;
  }
  *a2 = *(_DWORD *)(v11 + 12);
  *a5 = *(_DWORD *)(v11 + 8);
  v12 = *(_DWORD *)(v11 + 8);
  if ( a4 >= v12 )
  {
    memmove(a3, v11 + 16, v12);
    v13 = 0;
  }
  else
  {
    v13 = -1073741789;
  }
  v17 = v13;
LABEL_17:
  v14 = (unsigned int *)(a1 + 48);
  __dmb(0xBu);
  do
    v15 = __ldrex(v14);
  while ( v15 == 17 && __strex(0, v14) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v14);
  KeAbPostRelease((unsigned int)v14);
  return v17;
}
