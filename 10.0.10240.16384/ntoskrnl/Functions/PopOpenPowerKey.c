// PopOpenPowerKey 
 
int __fastcall PopOpenPowerKey(int a1)
{
  return PopOpenKey(a1, L"Control\\Session Manager\\Power", 131103);
}
