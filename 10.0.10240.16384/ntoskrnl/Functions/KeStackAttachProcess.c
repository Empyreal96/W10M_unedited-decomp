// KeStackAttachProcess 
 
int __fastcall KeStackAttachProcess(int a1)
{
  return KiStackAttachProcess(a1, 0);
}
