// ViDdiBuildWmiRegInfoData 
 
int __fastcall ViDdiBuildWmiRegInfoData(int a1, int a2)
{
  int result; // r0
  __int16 v6; // r3
  unsigned int v7; // r5
  int v8; // r2
  int v9; // r0
  __int16 v10; // r3

  if ( a2 != 0 )
  {
    *(_DWORD *)(a2 + 16) = 1;
    *(_DWORD *)(a2 + 20) = 506210688;
    *(_DWORD *)(a2 + 24) = 1185609691;
    *(_DWORD *)(a2 + 28) = 881266306;
    *(_DWORD *)(a2 + 32) = 1277149948;
    *(_DWORD *)(a2 + 36) = 0;
    *(_DWORD *)(a2 + 40) = 0;
    *(_DWORD *)(a2 + 44) = 0;
  }
  result = 48;
  if ( !a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 8) = 48;
      *(_WORD *)(a2 + 48) = ViDdiWmiMofKey;
      v6 = ViDdiWmiMofKey;
      *(_DWORD *)(a2 + 52) = a2 + 56;
      *(_WORD *)(a2 + 50) = v6;
      memmove(a2 + 56, dword_908044, (unsigned __int16)ViDdiWmiMofKey);
    }
    v7 = ((unsigned __int16)ViDdiWmiMofKey + 57) & 0xFFFFFFFE;
    if ( a2 )
    {
      *(_DWORD *)(a2 + 12) = v7;
      v8 = v7 + a2;
      v9 = v7 + a2 + 8;
      *(_WORD *)v8 = ViDdiWmiMofResourceName;
      v10 = ViDdiWmiMofResourceName;
      *(_DWORD *)(v8 + 4) = v9;
      *(_WORD *)(v8 + 2) = v10;
      memmove(v9, dword_90803C, (unsigned __int16)ViDdiWmiMofResourceName);
    }
    result = (unsigned __int16)ViDdiWmiMofResourceName + v7 + 8;
  }
  if ( a2 )
  {
    *(_DWORD *)a2 = result;
    *(_DWORD *)(a2 + 4) = 0;
  }
  return result;
}
