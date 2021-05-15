// sub_81C604 
 
void sub_81C604()
{
  int v0; // r6

  DbgPrint("%s: Sending legacy event to UMPO, code=%d\n", "PopUmpoSendLegacyEvent", *(_DWORD *)(v0 + 4));
  JUMPOUT(0x7BCAFC);
}
