// IoApplyPriorityInfoThread 
 
int __fastcall IoApplyPriorityInfoThread(_DWORD *a1, _DWORD *a2, int a3)
{
  int v7; // r4
  unsigned int *v8; // r8
  unsigned int v9; // r0
  unsigned int v10; // r6
  unsigned int v11; // r1
  int v12; // r6
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r6
  unsigned int v16; // r0
  int v17; // r1
  int v18; // [sp+Ch] [bp-2Ch]
  int v19; // [sp+10h] [bp-28h]
  int v20; // [sp+14h] [bp-24h]

  if ( a1[1] == 0xFFFF )
    return sub_52164C();
  v7 = a1[3];
  v8 = (unsigned int *)(a3 + 960);
  v9 = *(_DWORD *)(a3 + 960);
  __dmb(0xBu);
  do
  {
    v10 = v9;
    __dmb(0xBu);
    do
      v11 = __ldrex(v8);
    while ( v11 == v9 && __strex(v9 & 0xFFFFF1FF | (v7 << 9), v8) );
    v9 = v11;
    __dmb(0xBu);
  }
  while ( v11 != v10 );
  v12 = (v10 >> 9) & 7;
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(a3, 1332, v12, v7, 0);
  if ( v7 != v12 )
    KeAbProcessBaseIoPriorityChange(a3, v12, v7);
  v13 = a1[2];
  v20 = v12;
  if ( v13 == -1 )
  {
    v19 = -1;
  }
  else
  {
    v14 = *v8;
    __dmb(0xBu);
    do
    {
      v15 = v14;
      __dmb(0xBu);
      do
        v16 = __ldrex(v8);
      while ( v16 == v14 && __strex(v14 & 0xFFFF8FFF | (v13 << 12), v8) );
      v14 = v16;
      __dmb(0xBu);
    }
    while ( v16 != v15 );
    if ( (dword_682604 & 0x2000) != 0 )
      EtwTracePriority(a3, 1331, (v15 >> 12) & 7, v13, 0);
    v19 = (v15 >> 12) & 7;
  }
  v17 = a1[1];
  if ( v17 == -1 )
  {
    v18 = -1;
  }
  else
  {
    v18 = *(char *)(a3 + 347);
    KeSetActualBasePriorityThread(a3, v17);
  }
  if ( a2 )
  {
    *a2 = 16;
    a2[1] = v18;
    a2[2] = v19;
    a2[3] = v20;
  }
  return 0;
}
