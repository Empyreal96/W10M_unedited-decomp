// SepSetLogonSessionToken 
 
int __fastcall SepSetLogonSessionToken(int result)
{
  int v1; // r5
  int v2; // r3
  int v3; // r4
  unsigned int *v4; // r2
  unsigned int v5; // r1
  int v6; // [sp+10h] [bp-28h] BYREF
  int v7[8]; // [sp+18h] [bp-20h] BYREF

  v1 = result;
  if ( !*(_DWORD *)(*(_DWORD *)(result + 192) + 32) )
  {
    v2 = *(_DWORD *)(result + 176);
    if ( (v2 & 0x10) == 0 && (v2 & 8) == 0 )
    {
      v6 = 0;
      v7[0] = 24;
      v7[1] = 0;
      v7[2] = 0;
      v7[3] = 0;
      v7[4] = 0;
      v7[5] = 0;
      result = SepDuplicateToken(result, (int)v7, 0, 1, 0, 0, 0, &v6);
      if ( result >= 0 )
      {
        v3 = v6;
        result = SepStopReferencingLogonSession(v6);
        if ( result < 0 )
          goto LABEL_11;
        __dmb(0xBu);
        v4 = (unsigned int *)(*(_DWORD *)(v1 + 192) + 32);
        do
          v5 = __ldrex(v4);
        while ( !v5 && __strex(v3, v4) );
        __dmb(0xBu);
        if ( v5 )
LABEL_11:
          result = ObfDereferenceObject(v3);
      }
    }
  }
  return result;
}
