// MiDeleteAllPartialCloneVads 
 
unsigned int __fastcall MiDeleteAllPartialCloneVads(int a1)
{
  int v1; // r6
  _DWORD *v2; // r4
  _DWORD *i; // r3
  _DWORD *v4; // r3
  int v5; // r5
  _DWORD *v6; // r2
  int v7; // r0
  _BYTE v9[40]; // [sp-4h] [bp-28h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3);
  KiStackAttachProcess(a1, 0, (int)v9);
  v2 = 0;
  for ( i = *(_DWORD **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 636); i; i = (_DWORD *)*i )
    v2 = i;
  while ( v2 )
  {
    v4 = (_DWORD *)v2[1];
    v5 = (int)v2;
    v6 = v2;
    if ( v4 )
    {
      do
      {
        v2 = v4;
        v4 = (_DWORD *)*v4;
      }
      while ( v4 );
    }
    else
    {
      while ( 1 )
      {
        v2 = (_DWORD *)(v2[2] & 0xFFFFFFFC);
        if ( !v2 || (_DWORD *)*v2 == v6 )
          break;
        v6 = v2;
      }
    }
    MiLockVad(v1 & 0xFFFFFFC0, v5);
    v7 = MiReferenceVad(v5);
    MiDeleteVad(v7, 0x40000000);
  }
  return KiUnstackDetachProcess((unsigned int)v9, 0);
}
