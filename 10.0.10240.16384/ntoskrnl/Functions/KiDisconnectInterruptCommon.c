// KiDisconnectInterruptCommon 
 
int __fastcall KiDisconnectInterruptCommon(int a1, int a2, int a3)
{
  int v4; // r6
  int v5; // r4
  int v8; // r8
  unsigned int *v9; // r2
  unsigned int v10; // r0
  char v11[4]; // [sp+0h] [bp-58h] BYREF
  int v12; // [sp+4h] [bp-54h]
  int v13[2]; // [sp+8h] [bp-50h] BYREF
  int v14; // [sp+10h] [bp-48h]
  char v15[4]; // [sp+18h] [bp-40h] BYREF
  int v16; // [sp+1Ch] [bp-3Ch]
  int v17[2]; // [sp+20h] [bp-38h] BYREF
  char var30[52]; // [sp+28h] [bp-30h] BYREF

  v4 = -1073741585;
  v13[0] = 0;
  v13[1] = a3;
  v14 = 0;
  v5 = *(_DWORD *)(a2 + 92);
  v12 = 0;
  if ( v5 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    v15[0] = 1;
    v15[1] = 0;
    v15[2] = 4;
    v16 = 0;
    v17[1] = (int)v17;
    v17[0] = (int)v17;
    v13[0] = (int)v15;
  }
  if ( a1 )
    return sub_50F928();
  KiAcquireInterruptConnectLock(*(_DWORD *)(a2 + 52), v11, var30);
  v8 = (unsigned __int8)v11[0];
  if ( *(_BYTE *)(a2 + 51) && (*(_DWORD *)(a2 + 60) & 2) == 0 )
  {
    if ( *(_WORD *)(a2 + 58) )
    {
      __dmb(0xBu);
      v9 = (unsigned int *)(a2 + 60);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 2, v9) );
      __dmb(0xBu);
      *(_DWORD *)(a2 + 88) = v13;
      v12 = 1;
    }
    else
    {
      v4 = KiDisconnectInterruptInternal(a2, a3);
    }
  }
  KiReleaseInterruptConnectLock(v8, var30);
  if ( v13[0] )
  {
    if ( v12 )
    {
      KiSignalWaitDisconnectLock();
      v4 = v14;
    }
  }
  return v4;
}
