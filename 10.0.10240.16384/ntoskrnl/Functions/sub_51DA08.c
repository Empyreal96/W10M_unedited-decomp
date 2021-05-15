// sub_51DA08 
 
void sub_51DA08()
{
  int v0; // r5

  if ( *(_DWORD *)(v0 + 4) != 521 )
    SepAuditFailedRaisedIrql(-1073741670);
  JUMPOUT(0x4E0AD0);
}
