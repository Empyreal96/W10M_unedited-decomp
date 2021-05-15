// KiDisconnectInterruptCommon 
 
void __fastcall KiDisconnectInterruptCommon(int a1, int a2, int a3)
{
  char *v4; // r4
  char *v6; // r3
  int v7; // r8
  unsigned int *v8; // r2
  unsigned int v9; // r0
  char v10[4]; // [sp+0h] [bp-58h] BYREF
  int v11; // [sp+4h] [bp-54h]
  unsigned int v12[4]; // [sp+8h] [bp-50h] BYREF
  char v13[4]; // [sp+18h] [bp-40h] BYREF
  int v14; // [sp+1Ch] [bp-3Ch]
  int v15[2]; // [sp+20h] [bp-38h] BYREF
  char var30[52]; // [sp+28h] [bp-30h] BYREF

  v12[0] = 0;
  v12[1] = a3;
  v12[2] = 0;
  v4 = *(char **)(a2 + 92);
  v11 = 0;
  v6 = (char *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( v4 != v6 )
  {
    v13[0] = 1;
    v13[1] = 0;
    v13[2] = 4;
    v14 = 0;
    v15[1] = (int)v15;
    v15[0] = (int)v15;
    v6 = v13;
    v12[0] = (unsigned int)v13;
  }
  if ( a1 )
  {
    sub_50F928();
  }
  else
  {
    KiAcquireInterruptConnectLock(*(_DWORD *)(a2 + 52), v10, (int)var30, (int)v6);
    v7 = (unsigned __int8)v10[0];
    if ( *(_BYTE *)(a2 + 51) && (*(_DWORD *)(a2 + 60) & 2) == 0 )
    {
      if ( *(_WORD *)(a2 + 58) )
      {
        __dmb(0xBu);
        v8 = (unsigned int *)(a2 + 60);
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 | 2, v8) );
        __dmb(0xBu);
        *(_DWORD *)(a2 + 88) = v12;
        v11 = 1;
      }
      else
      {
        KiDisconnectInterruptInternal(a2, a3);
      }
    }
    KiReleaseInterruptConnectLock(v7, (int)var30);
    if ( v12[0] )
    {
      if ( v11 )
        KiSignalWaitDisconnectLock(v12[0], 1);
    }
  }
}
