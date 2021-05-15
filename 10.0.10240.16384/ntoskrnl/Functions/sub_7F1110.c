// sub_7F1110 
 
void __fastcall sub_7F1110(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  PopBcdEstablishResumeObject(a8, 0);
  PopBcdClearPendingResume(a8);
  BcdCloseStore(a8);
  JUMPOUT(0x78BE32);
}
