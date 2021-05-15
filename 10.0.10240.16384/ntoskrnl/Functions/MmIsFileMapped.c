// MmIsFileMapped 
 
int __fastcall MmIsFileMapped(int a1, int a2)
{
  int v2; // r6
  int v3; // r9
  int v4; // r7
  int v5; // r10
  _DWORD *v6; // r3
  _DWORD *v7; // r4
  _DWORD *v8; // r3
  int v9; // r8
  _DWORD *v10; // r2
  int v11; // r5
  int v12; // r0
  int v15; // [sp+4h] [bp-3Ch]
  char v16[56]; // [sp+8h] [bp-38h] BYREF

  v2 = a1;
  v15 = *(_DWORD *)(a2 + 20);
  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v4 + 0x74) == a1 )
  {
    v5 = 0;
  }
  else
  {
    KiStackAttachProcess(a1, 0, (int)v16);
    v5 = 1;
  }
  LOCK_ADDRESS_SPACE_SHARED(v4, v2);
  v6 = *(_DWORD **)(v2 + 636);
  v7 = 0;
  while ( v6 )
  {
    v7 = v6;
    v6 = (_DWORD *)*v6;
  }
  if ( v7 )
  {
    do
    {
      v8 = (_DWORD *)v7[1];
      v9 = (int)v7;
      v10 = v7;
      if ( v8 )
      {
        do
        {
          v7 = v8;
          v8 = (_DWORD *)*v8;
        }
        while ( v8 );
      }
      else
      {
        while ( 1 )
        {
          v7 = (_DWORD *)(v7[2] & 0xFFFFFFFC);
          if ( !v7 || (_DWORD *)*v7 == v10 )
            break;
          v10 = v7;
        }
      }
      if ( (*(_DWORD *)(v9 + 28) & 0x8000) == 0 )
      {
        MiLockVad(v4, v9);
        if ( !MiVadDeleted(v9) )
        {
          v11 = **(_DWORD **)(v9 + 44);
          if ( *(_DWORD *)(v11 + 32) )
          {
            v12 = MI_REFERENCE_CONTROL_AREA_FILE(**(_DWORD **)(v9 + 44));
            if ( *(_DWORD *)(v12 + 20) == v15 )
              v3 = 1;
            MI_DEREFERENCE_CONTROL_AREA_FILE(v11, v12);
          }
        }
        MiUnlockVad(v4, v9);
        if ( v3 == 1 )
          break;
      }
    }
    while ( v7 );
    v2 = a1;
  }
  UNLOCK_ADDRESS_SPACE_SHARED(v4, v2);
  if ( v5 == 1 )
    KiUnstackDetachProcess((unsigned int)v16, 0);
  return v3;
}
