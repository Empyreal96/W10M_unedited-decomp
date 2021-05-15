// MiZeroPageFile 
 
int __fastcall MiZeroPageFile(int a1)
{
  __int64 v1; // kr00_8
  int v2; // r7
  unsigned int v3; // r8
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v6; // r10
  int v7; // r0
  int v8; // r0
  int v10[2]; // [sp+0h] [bp-38h] BYREF
  unsigned __int64 v11; // [sp+8h] [bp-30h] BYREF
  char v12[40]; // [sp+10h] [bp-28h] BYREF

  v1 = *(_QWORD *)(a1 + 16);
  ExFreePoolWithTag(a1);
  v2 = 0;
  v3 = 0;
  v4 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v1 + 116), (unsigned int)v12);
  v5 = 1;
  v6 = *(_DWORD *)(v1 + 64) + 4;
  if ( *(_DWORD *)v1 > 1u )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(v6 + 4);
      if ( ((*(int *)(v7 + 4 * (v5 >> 5)) >> (v5 & 0x1F)) & 1) == 0 )
        break;
      if ( v4 )
        goto LABEL_9;
LABEL_10:
      if ( v2 )
      {
        KeReleaseInStackQueuedSpinLock((int)v12);
        v11 = (unsigned __int64)v3 << 12;
        v10[1] = v4 >> 20;
        v8 = *(_DWORD *)(v1 + 32);
        v10[0] = v4 << 12;
        MmZeroPageWrite(v8, (int)&v11, (int)v10, 0);
        v2 = 0;
        KeAcquireInStackQueuedSpinLock((unsigned int *)(v1 + 116), (unsigned int)v12);
        v6 = *(_DWORD *)(v1 + 64) + 4;
        RtlClearBits((_BYTE *)v6, v3, v4);
        v4 = 0;
      }
      if ( ++v5 >= *(_DWORD *)v1 )
        goto LABEL_13;
    }
    *(_BYTE *)((v5 >> 3) + v7) |= 1 << (v5 & 7);
    if ( !v4 )
      v3 = v5;
    if ( ++v4 != 16 && v5 != *(_DWORD *)v1 - 1 )
      goto LABEL_10;
LABEL_9:
    v2 = 1;
    goto LABEL_10;
  }
LABEL_13:
  KeReleaseInStackQueuedSpinLock((int)v12);
  return KeSetEvent(SHIDWORD(v1), 0, 0);
}
