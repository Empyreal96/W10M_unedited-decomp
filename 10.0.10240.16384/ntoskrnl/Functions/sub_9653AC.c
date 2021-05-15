// sub_9653AC 
 
void __fastcall sub_9653AC(_DWORD *a1, __int16 a2, _DWORD *a3)
{
  while ( *a3 )
  {
    if ( ((unsigned __int16)++a3 & 0xFFF) == 0 )
    {
      if ( ((a2 + 4) & 0xFFF) != 0 )
        JUMPOUT(0x9566C4);
LABEL_7:
      JUMPOUT(0x9566B2);
    }
  }
  *a1 = a3;
  goto LABEL_7;
}
