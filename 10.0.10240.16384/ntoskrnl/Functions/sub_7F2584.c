// sub_7F2584 
 
void sub_7F2584()
{
  _DWORD *v0; // r4
  const void **v1; // r5
  _DWORD *v2; // r6
  int v3[11]; // [sp+38h] [bp-78h] BYREF

  ZwClose();
  *v0 = 0;
  memset(v3, 0, sizeof(v3));
  v3[0] = 0x100000;
  v3[4] = 256;
  if ( ZwAlpcAcceptConnectPort() >= 0 )
  {
    if ( (*v2 & 0x10000000) != 0 )
      DbgPrint("%s: Monitor Connected, port=%p\n", "PopMonitorProcessLoop", *v1);
  }
  else
  {
    ZwAlpcAcceptConnectPort();
  }
  JUMPOUT(0x7089F8);
}
