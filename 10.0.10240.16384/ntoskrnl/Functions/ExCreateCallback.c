// ExCreateCallback 
 
int __fastcall ExCreateCallback(_DWORD *a1, int *a2, int a3, char a4)
{
  unsigned int v6; // r8
  int *v7; // r1
  int v8; // r4
  int v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r5
  int v13; // r0
  int v14; // r4
  int v16; // r6
  int v17; // r0
  unsigned int v18; // r2
  int **v19; // r0
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  __int16 v24; // r3
  int v25; // [sp+18h] [bp-48h] BYREF
  _DWORD *v26; // [sp+1Ch] [bp-44h] BYREF
  _DWORD *v27; // [sp+20h] [bp-40h]
  _DWORD v28[3]; // [sp+28h] [bp-38h] BYREF
  int v29; // [sp+34h] [bp-2Ch]
  int v30; // [sp+38h] [bp-28h]
  int v31; // [sp+3Ch] [bp-24h]

  v27 = a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *a2;
  v9 = a2[1];
  v10 = a2[2];
  v11 = a2[3];
  v7 = a2 + 4;
  v28[0] = v8;
  v28[1] = v9;
  v28[2] = v10;
  v29 = v11;
  v12 = v7[1];
  v30 = *v7;
  v31 = v12;
  v13 = 0;
  v25 = 0;
  v26 = 0;
  v29 = v11 | 0x200;
  if ( v10 )
  {
    v14 = ObOpenObjectByName((int)v28, ExCallbackObjectType, 0, 0, 0, 0, &v25);
    v13 = v25;
  }
  else
  {
    v14 = -1073741823;
  }
  if ( v14 >= 0 )
    goto LABEL_4;
  if ( !a3 )
    goto LABEL_27;
  v14 = ObCreateObject(0, (_DWORD *)ExCallbackObjectType, (int)v28, 0, 0, 28, 0, 0, &v26);
  if ( v14 < 0 )
    return v14;
  v16 = (int)v26;
  *v26 = 1819042115;
  *(_BYTE *)(v16 + 16) = a4;
  *(_DWORD *)(v16 + 8) = v16 + 8;
  *(_DWORD *)(v16 + 12) = v16 + 8;
  *(_DWORD *)(v16 + 4) = 0;
  --*(_WORD *)(v6 + 310);
  v17 = KeAbPreAcquire((unsigned int)&ExpCallbackListLock, 0, 0);
  do
    v18 = __ldrex((unsigned __int8 *)&ExpCallbackListLock);
  while ( __strex(v18 | 1, (unsigned __int8 *)&ExpCallbackListLock) );
  __dmb(0xBu);
  if ( (v18 & 1) == 0 )
  {
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    v19 = (int **)dword_61A16C;
    *(_DWORD *)(v16 + 20) = &ExpCallbackListHead;
    *(_DWORD *)(v16 + 24) = v19;
    if ( *v19 != &ExpCallbackListHead )
      __fastfail(3u);
    *v19 = (int *)(v16 + 20);
    __pld(&ExpCallbackListLock);
    dword_61A16C = v16 + 20;
    v20 = ExpCallbackListLock;
    if ( (ExpCallbackListLock & 0xFFFFFFF0) > 0x10 )
      v21 = ExpCallbackListLock - 16;
    else
      v21 = 0;
    if ( (ExpCallbackListLock & 2) != 0 )
      goto LABEL_31;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&ExpCallbackListLock);
    while ( v22 == v20 && __strex(v21, (unsigned int *)&ExpCallbackListLock) );
    if ( v22 != v20 )
LABEL_31:
      ExfReleasePushLock(&ExpCallbackListLock, v20);
    v23 = KeAbPostRelease((unsigned int)&ExpCallbackListLock);
    v24 = *(_WORD *)(v6 + 310) + 1;
    *(_WORD *)(v6 + 310) = v24;
    if ( !v24 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      KiCheckForKernelApcDelivery(v23);
    v14 = ObInsertObject(v16, 0, 1, 0, 0, (int)&v25);
    v13 = v25;
LABEL_27:
    if ( v14 >= 0 )
    {
LABEL_4:
      v14 = ObReferenceObjectByHandle(v13, 0, ExCallbackObjectType, 0, (int)&v26, 0);
      ZwClose();
      if ( v14 >= 0 )
        *v27 = v26;
    }
    return v14;
  }
  return sub_810858(v17);
}
