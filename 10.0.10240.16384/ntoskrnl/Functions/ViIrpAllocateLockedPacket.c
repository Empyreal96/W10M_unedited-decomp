// ViIrpAllocateLockedPacket 
 
_DWORD *__fastcall ViIrpAllocateLockedPacket(char a1, int a2)
{
  unsigned __int16 v3; // r10
  _DWORD *v5; // r5
  int v6; // r4
  unsigned int v7; // r7
  int v8; // r6
  _DWORD *v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1

  v3 = 40 * a1 + 112;
  v5 = 0;
  v6 = VeAllocatePoolWithTagPriority(640, v3, 728789577, 32);
  if ( v6 )
  {
    v7 = 0;
    v8 = 0;
    if ( a2
      && (v7 = 4096,
          v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
          PsChargeProcessNonPagedPoolQuota(v8, 4096) < 0) )
    {
      ExFreePoolWithTag(v6);
    }
    else
    {
      IoInitializeIrp(v6, v3, a1);
      v9 = (_DWORD *)VfPacketCreateAndLock(v6);
      v5 = v9;
      if ( v9 )
      {
        v9[9] |= 0x200008u;
        __dmb(0xBu);
        v10 = v9 + 3;
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 + 1, v10) );
        __dmb(0xBu);
        ++v9[4];
        *(_DWORD *)(v6 + 8) |= 0x40000000u;
        if ( a2 )
        {
          *(_BYTE *)(v6 + 39) |= 1u;
          v9[14] = v7;
          v9[15] = v8;
          ObfReferenceObjectWithTag(v8);
        }
      }
      else
      {
        ExFreePoolWithTag(v6);
        if ( a2 )
          PsReturnProcessNonPagedPoolQuota(v8, v7);
      }
    }
  }
  return v5;
}
