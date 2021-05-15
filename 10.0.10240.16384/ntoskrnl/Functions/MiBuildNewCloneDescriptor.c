// MiBuildNewCloneDescriptor 
 
int __fastcall MiBuildNewCloneDescriptor(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r6
  int v6; // r4
  _DWORD *v7; // r0
  unsigned int v8; // r7
  int v9; // r10
  unsigned int v10; // r5

  v4 = 16 * a2 + 12;
  if ( PsChargeProcessNonPagedPoolQuota(a1, v4) >= 0 )
  {
    v6 = ExAllocatePoolWithTag(512, 48, 1682140493);
    if ( v6 )
    {
      v7 = (_DWORD *)ExAllocatePoolWithTag(-2147483647, v4, 1816358221);
      v8 = (unsigned int)v7;
      if ( v7 )
      {
        *v7 = 0;
        v7[1] = 0;
        v7[2] = 0;
        v7[3] = 0;
        v9 = ExAllocatePoolWithTag(512, 12, 1749249357);
        if ( v9 )
        {
          v10 = 0;
          while ( MiLockPagedAddress(v10 + v8) )
          {
            v10 += 4096;
            if ( v10 >= v4 )
            {
              *(_QWORD *)v9 = a2 | 0x100000000i64;
              *(_DWORD *)(v9 + 8) = v8;
              *(_DWORD *)(v6 + 12) = v8;
              *(_DWORD *)(v6 + 16) = v8 + 16 * a2 - 16;
              *(_QWORD *)(v6 + 20) = a2;
              *(_DWORD *)(v6 + 28) = v9;
              *(_DWORD *)(v6 + 32) = v4;
              *(_DWORD *)(v6 + 40) = a3;
              *(_DWORD *)(v6 + 44) = a4;
              return v6;
            }
          }
          while ( v10 )
          {
            v10 -= 4096;
            MiUnlockPagedAddress(v10 + v8);
          }
          ExFreePoolWithTag(v9);
        }
        ExFreePoolWithTag(v8);
      }
      PsReturnProcessNonPagedPoolQuota(a1, v4);
      ExFreePoolWithTag(v6);
    }
    else
    {
      PsReturnProcessNonPagedPoolQuota(a1, v4);
    }
  }
  return 0;
}
