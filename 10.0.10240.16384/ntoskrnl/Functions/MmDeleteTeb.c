// MmDeleteTeb 
 
unsigned int __fastcall MmDeleteTeb(int a1, unsigned int a2)
{
  int v3; // r0
  _DWORD *v4; // r2
  int v5; // r1
  int v7; // [sp-4h] [bp-28h] BYREF
  char v8[32]; // [sp+4h] [bp-20h] BYREF

  KiStackAttachProcess(a1, 0, (int)v8);
  v3 = MiObtainReferencedVad(a2, &v7);
  if ( v3 )
  {
    v4 = *(_DWORD **)(v3 + 36);
    v5 = 0;
    if ( v4 )
    {
      while ( v4[1] != 2 || (unsigned int)++v5 <= 1 )
      {
        v4 = (_DWORD *)*v4;
        if ( !v4 )
        {
          if ( v5 != 1 )
            break;
          MiDeleteVad(v3, 0);
          return KiUnstackDetachProcess((unsigned int)v8, 0);
        }
      }
    }
    MiUnlockAndDereferenceVad(v3);
  }
  return KiUnstackDetachProcess((unsigned int)v8, 0);
}
