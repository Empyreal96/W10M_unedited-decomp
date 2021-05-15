// IoDumpStackResumeCapable 
 
int __fastcall IoDumpStackResumeCapable(int a1)
{
  int result; // r0

  result = 0;
  if ( CrashdmpImageEntry )
  {
    if ( dword_63766C )
      result = dword_63766C(a1);
  }
  return result;
}
