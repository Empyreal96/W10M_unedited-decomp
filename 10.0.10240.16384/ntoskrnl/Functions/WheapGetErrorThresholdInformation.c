// WheapGetErrorThresholdInformation 
 
int __fastcall WheapGetErrorThresholdInformation(int result, _DWORD *a2, _DWORD *a3)
{
  int v3; // r3
  int v4; // r4
  int v5; // r5
  unsigned __int8 *v7; // r3
  int v8; // r2

  v3 = *(_DWORD *)(result + 81);
  v4 = 0;
  v5 = 0;
  if ( v3 == 1 )
  {
    v7 = (unsigned __int8 *)(result + 121);
  }
  else
  {
    if ( v3 == 2 || v3 == 4 || v3 != 5 && v3 != 8 )
      goto LABEL_14;
    v7 = (unsigned __int8 *)(result + 137);
  }
  if ( v7 )
  {
    v8 = *v7;
    if ( v8 == 1 || v8 == 2 || v8 == 3 || v8 == 4 )
    {
      v4 = *((_DWORD *)v7 + 5);
      v5 = *((_DWORD *)v7 + 6);
    }
  }
LABEL_14:
  *a2 = v5;
  *a3 = v4;
  return result;
}
