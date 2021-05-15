// NormBuffer__RecheckStartCombinations 
 
int __fastcall NormBuffer__RecheckStartCombinations(int result)
{
  int v1; // r4
  unsigned __int16 *v2; // r2
  int v3; // r3
  int v4; // r6
  int v5; // r0
  int v6; // r7
  int v7; // r8
  int v8; // r5
  int v9; // r8
  int v10; // r0
  unsigned __int16 *v11; // r5
  unsigned __int8 v12; // [sp+8h] [bp-20h] BYREF
  char v13[3]; // [sp+9h] [bp-1Fh] BYREF
  unsigned __int16 *v14; // [sp+Ch] [bp-1Ch] BYREF

  v1 = result;
  v2 = *(unsigned __int16 **)(result + 44);
  v3 = *(unsigned __int8 *)(result + 53);
  v14 = v2;
  if ( v3 == 64 )
  {
    v4 = 0;
    if ( v2 != *(unsigned __int16 **)(result + 20) )
    {
      do
      {
        v5 = NormBuffer__GetCurrentOutputChar(result, &v14);
        v6 = *(_DWORD *)(v1 + 68);
        v7 = v5;
        result = Normalization__GetCharacterInfo(v6, v5, v13, &v12);
        v8 = (unsigned __int8)v13[0];
        if ( (unsigned __int8)v13[0] != v4 )
        {
          if ( v12 == 192 )
          {
            result = Normalization__CanCombinableCharactersCombine(v6, *(_DWORD *)(v1 + 48), v7);
            v9 = result;
            if ( result )
            {
              Normalization__GetCharacterInfo(v6, result, v13, &v12);
              v10 = NormBuffer__SetLastStart(v1, v9, (unsigned __int8)v13[0], v12, 0);
              v11 = v14;
              result = NormBuffer__RemoveCharacter(v10, v14);
              if ( *(_BYTE *)(v1 + 53) != 64 )
                return result;
              continue;
            }
          }
          v4 = v8;
        }
        v11 = ++v14;
      }
      while ( v11 != *(unsigned __int16 **)(v1 + 20) );
    }
  }
  return result;
}
