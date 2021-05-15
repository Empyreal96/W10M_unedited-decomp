// sub_7EAD68 
 
void __fastcall sub_7EAD68(_WORD *a1)
{
  int v1; // r5
  int v2; // r6
  unsigned __int16 *v3; // r0

  if ( EtwpUpdateStackTracing(v2, a1 + 2, (unsigned __int16)(4 * *a1 - 4) >> 2) >= 0 )
  {
    v3 = EtwpGetFlagExtension(v1, 5);
    if ( v3 )
    {
      if ( (unsigned __int16)(4 * *v3 - 4) == 8 )
        EtwpEnableStackCaching(v2, *((_DWORD *)v3 + 1), *((_DWORD *)v3 + 2));
    }
  }
  JUMPOUT(0x707696);
}
