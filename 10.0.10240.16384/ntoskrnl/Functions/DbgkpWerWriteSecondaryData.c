// DbgkpWerWriteSecondaryData 
 
int __fastcall DbgkpWerWriteSecondaryData(int a1)
{
  int v1; // r5
  int result; // r0

  v1 = *(_DWORD *)(a1 + 112);
  if ( !v1 )
    return 0;
  result = ZwWriteFile();
  if ( result >= 0 )
  {
    do
    {
      result = ZwWriteFile();
      if ( result < 0 )
        break;
      result = ZwWriteFile();
      if ( result < 0 )
        break;
      v1 = *(_DWORD *)(v1 + 28);
    }
    while ( v1 );
  }
  return result;
}
