// WmipGetGuidPropertiesFromGuidEntry 
 
int __fastcall WmipGetGuidPropertiesFromGuidEntry(int result, int a2)
{
  _DWORD *v2; // r2

  *(_DWORD *)(result + 16) = 2;
  *(_DWORD *)(result + 20) = 0;
  *(_BYTE *)(result + 32) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 28) = 0;
  v2 = *(_DWORD **)(a2 + 32);
  if ( v2 != (_DWORD *)(a2 + 32) )
  {
    while ( 1 )
    {
      if ( (v2[2] & 0x8000) != 0 )
        *(_DWORD *)(result + 16) = 3;
      if ( (v2[2] & 0x6000) != 0 )
        *(_BYTE *)(result + 32) = 1;
      if ( (v2[2] & 0x81000) == 528384 )
        break;
      v2 = (_DWORD *)*v2;
      if ( v2 == (_DWORD *)(a2 + 32) )
        goto LABEL_10;
    }
    *(_DWORD *)(result + 16) = 0;
  }
LABEL_10:
  if ( *(_DWORD *)(a2 + 80) == -1 )
  {
    if ( *(_QWORD *)(a2 + 88) )
    {
      *(_BYTE *)(result + 32) = 1;
      *(_DWORD *)(result + 20) = *(unsigned __int16 *)(a2 + 88);
      *(_DWORD *)(result + 24) = *(unsigned __int8 *)(a2 + 90);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a2 + 92);
    }
  }
  return result;
}
