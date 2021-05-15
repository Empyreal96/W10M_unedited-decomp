// MiZeroInParallel 
 
int __fastcall MiZeroInParallel(unsigned int a1, unsigned int a2, char a3)
{
  int v3; // r3
  unsigned int v4; // r8
  unsigned int v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r5
  unsigned int v8; // r7
  int v9; // r10
  _DWORD *v10; // r1
  unsigned int v11; // r0
  int v12; // r3
  int v13; // r7
  int result; // r0
  int v15; // r6
  int v16; // r4
  unsigned int v17; // r5
  int v19; // [sp+18h] [bp-58h]
  unsigned int v21; // [sp+24h] [bp-4Ch]
  int v22; // [sp+28h] [bp-48h] BYREF
  _DWORD v23[2]; // [sp+30h] [bp-40h] BYREF
  unsigned int v24[2]; // [sp+38h] [bp-38h] BYREF
  char v25[4]; // [sp+40h] [bp-30h] BYREF
  int v26; // [sp+44h] [bp-2Ch]
  int v27[10]; // [sp+48h] [bp-28h] BYREF

  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = v3 & 0xFFFFFFC0;
  v21 = v3 & 0xFFFFFFC0;
  v5 = KeNumberProcessors_0;
  v19 = KeNumberProcessors_0;
  if ( (a3 & 8) != 0
    || (*(_DWORD *)((v3 & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
    || KeGetCurrentIrql() == 2
    || (MiFlags & 0x30) == 0 )
  {
    v5 = 0;
    v19 = 0;
  }
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = KeSetPriorityThread(v4, 15);
  v22 = v9;
  if ( a2 )
  {
    v10 = (_DWORD *)a1;
    v11 = (unsigned __int16)KeNumberNodes;
    while ( 1 )
    {
      if ( v10[3] == 0xFFFFF )
      {
        *v10 = 1;
      }
      else
      {
        *v10 = 0;
        ++v6;
        v7 += v10[2];
        if ( v11 > 1 )
          return sub_5141D0();
        v10[1] = -1;
      }
      ++v8;
      v10 += 4;
      if ( v8 >= a2 )
      {
        v5 = v19;
        v4 = v21;
        v9 = v22;
        break;
      }
    }
  }
  if ( v5 > v6 )
    v5 = v6;
  if ( v5 > v7 >> 12 )
    v5 = v7 >> 12;
  if ( v5 == 1 )
    v5 = 0;
  v12 = *(_DWORD *)(v4 + 116);
  v23[0] = v9;
  v23[1] = v12;
  v24[1] = a1;
  v25[0] = 7;
  v25[1] = 1;
  v25[2] = 4;
  v26 = 0;
  v27[1] = (int)v27;
  v27[0] = (int)v27;
  __dmb(0xBu);
  v13 = 0;
  v24[0] = v5;
  if ( v5 )
  {
    while ( PsCreateSystemThread(&v22, 0x1FFFFF, 0, 0, 0, MiZeroInParallelWorker, v23) >= 0 )
    {
      ObCloseHandle(v22, 0);
      if ( ++v13 >= v5 )
        goto LABEL_18;
    }
    v15 = v5 - v13;
    v16 = v13 - v5;
    do
      v17 = __ldrex(v24);
    while ( __strex(v17 + v16, v24) );
    if ( v17 == v15 )
      KeSignalGate(v25, 1, v24);
  }
LABEL_18:
  KeSetPriorityThread(v4, v9);
  if ( v13 )
    result = KeWaitForGate(v25, 0);
  else
    result = MiZeroInParallelWorker(v23);
  return result;
}
