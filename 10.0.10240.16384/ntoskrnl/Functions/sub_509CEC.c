// sub_509CEC 
 
void sub_509CEC()
{
  int v0; // r4
  _DWORD *v1; // r5

  v1 = *(_DWORD **)(v0 + 3860);
  __dmb(0xBu);
  if ( *v1 )
    RtlpSysVolFree();
  ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v1);
  JUMPOUT(0x429B70);
}
