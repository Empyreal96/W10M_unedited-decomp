// NtTestAlert 
 
int NtTestAlert()
{
  int result; // r0

  if ( KeTestAlertThread(*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)) )
    result = 257;
  else
    result = 0;
  return result;
}
