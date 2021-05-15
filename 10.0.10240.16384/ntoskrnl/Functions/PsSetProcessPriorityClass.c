// PsSetProcessPriorityClass 
 
int __fastcall PsSetProcessPriorityClass(int result, char a2)
{
  *(_BYTE *)(result + 375) = a2;
  return result;
}
