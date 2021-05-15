// ProbeForRead 
 
int __fastcall ProbeForRead(int result, int a2, int a3)
{
  if ( a2 )
  {
    if ( ((a3 - 1) & result) != 0 )
      sub_7E6284();
  }
  return result;
}
