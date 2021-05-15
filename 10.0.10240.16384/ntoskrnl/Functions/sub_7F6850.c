// sub_7F6850 
 
void __fastcall sub_7F6850(int a1)
{
  if ( a1 == -1073741740 )
  {
    KeDelayExecutionThread(0, 0, (unsigned int *)MiHalfSecond);
    JUMPOUT(0x71A108);
  }
  JUMPOUT(0x71A168);
}
