#include <iostream>

class Account
{
public:
	Account() 
		: account(0) {}

	Account(int sAccount)
		: account(sAccount) {}

	virtual const Account& Deposit(int money)
	{
		this->account += money;
		return *this;
	}

	void ShowDeposit(int money) const
	{
		std::cout
			<< "입금액 : "
			<< money
			<< '\n';
	}

	//Account& Withdraw(int money) const
	//{
	//	this->account -= money;
	//	return *this;
	//} 출금 구현 X

	int GetAccount() const
	{
		return account;
	}

	virtual void ShowAccount() const
	{
		std::cout
			<< "총 금액 : "
			<< account
			<< '\n';
	}

private:
	int account;
};

class CreditAccount : public Account
{
public:
	CreditAccount()
		: interestRatio(0.01f) { }
	CreditAccount(float sIntersetRaito)
		: interestRatio(sIntersetRaito) { }

	CreditAccount& SetInterestRatio(float sInteresetRatio)
	{
		this->interestRatio = sInteresetRatio;
		return *this;
	}

	virtual CreditAccount& Deposit(int money) override
	{
		int interestPayment = InterestPayment(money);
		this->ShowDeposit(money);
		ShowInterestPayment(interestPayment);
  		this->Account::Deposit(money + interestPayment);
		ShowAccount();
		return *this;
	}

	int InterestPayment(int money) const
	{
		return money * interestRatio;
	}

	void ShowInterestPayment(int interestPayment) const
	{
		std::cout
			<< "이자율 : "
			<< interestRatio
			<< "\n이자금 : "
			<< interestPayment
			<< '\n';
	}

private:
	float interestRatio;
};
class DonationAccount : public Account
{
public:
	DonationAccount()
		: donateRatio(0.01f) { }
	DonationAccount(float sdonateRaito)
		: donateRatio(sdonateRaito) { }

	DonationAccount& SetDonateRatio(float sDonateRatio)
	{
		this->donateRatio = sDonateRatio;
		return *this;
	}

	virtual DonationAccount& Deposit(int money) override 
		//이렇게 할 필요 없고 부모 클래스도 
		//void Deposit(int money)하는 게 낫다는 의견.
		//그래서 함수에서 멤버변수를 변환한 객체를 반환하는 것보다
		//함수 자체에서 멤버변수를 변환하는 게 낫다.
	{
		int donation = Donation(money);
		this->ShowDeposit(money);
		ShowDoantion(donation);
		this->Account::Deposit(money - donation);
		ShowAccount();
		return *this;
	}

	int Donation(const int money) const
	{
		return money * donateRatio;
	}

	void ShowDoantion(int interestPayment) const
	{
		std::cout
			<< "기부율 : "
			<< donateRatio
			<< "\n기부금 : "
			<< interestPayment
			<< '\n';
	}

private:
	float donateRatio;
};

void exam11()
{
	CreditAccount* credit = new CreditAccount();
	DonationAccount* donate = new DonationAccount();
	
	credit->Deposit(10000);
	donate->Deposit(10000);
}