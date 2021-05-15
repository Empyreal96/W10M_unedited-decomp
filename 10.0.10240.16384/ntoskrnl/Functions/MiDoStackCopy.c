// MiDoStackCopy 
 
int __fastcall MiDoStackCopy(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v5; // r1
  unsigned int v6; // r3
  int v7; // r4
  int v8; // r6
  int v9; // r7
  int result; // r0
  int v11[8]; // [sp+8h] [bp-20h] BYREF

  v5 = *a2;
  v11[1] = a3;
  v11[2] = a4;
  v6 = a2[6];
  v7 = MmPfnDatabase + 24 * v5;
  v11[0] = (int)a2;
  if ( v6 )
    v8 = 2;
  else
    v8 = 1;
  v9 = *(_DWORD *)v7;
  if ( !MI_IS_PFN(v5)
    || (*(_BYTE *)(v7 + 23) & 7) != 2
    || (*(_BYTE *)(v7 + 18) & 7) != 6
    || *(unsigned __int16 *)(v7 + 16) != v8
    || v9 == -5 )
  {
    a2[4] = -1073740748;
    goto LABEL_9;
  }
  if ( v9 != -3 || a2[3] == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0 | 1) )
    goto LABEL_9;
  result = KeExpandKernelStackAndCalloutInternal(MiJumpStackTarget, (int)v11, 12288, 5);
  if ( result < 0 )
  {
    a2[4] = result;
LABEL_9:
    result = MiJumpStackTarget(v11);
  }
  return result;
}
