// sub_54B254 
 
void sub_54B254()
{
  int v0; // r5
  int v1; // r6
  __int64 v2; // r2

  if ( *(_BYTE *)(v1 + 76) )
  {
    v2 = *(_QWORD *)(v0 + 24);
    if ( (v2 & 4) != 0 )
      goto LABEL_6;
    if ( *(_DWORD *)(v0 + 148) )
    {
      if ( *(_DWORD *)(v0 + 144) )
        JUMPOUT(0x4D2AE4);
      if ( (v2 & 2) != 0 )
LABEL_6:
        PopFxUpdateComponentPerfStateNominalChange(*(_DWORD *)(v1 + 24), *(_DWORD *)(v0 + 8), 0, *(_DWORD *)(v0 + 144));
    }
  }
  JUMPOUT(0x4D2AD2);
}
