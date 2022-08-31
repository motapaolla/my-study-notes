# Cloud

## Why is it cheaper?

- Lower your operating costs.
- Run your infrastructure more efficiently.
- Scale as your business needs change.

## Advantages

- **Reliability**: Depending on the service-level agreement that you choose, your cloud-based applications can provide a continuous user experience with no apparent downtime even when things go wrong.
- **Scalability**: Applications in the cloud can be scaled in two ways, while taking advantage of autoscaling:
    - *Vertically*: Computing capacity can be increased by adding RAM or CPUs to a virtual machine.
    - *Horizontally*: Computing capacity can be increased by adding instances of a resource, such as adding more virtual machines to your configuration.
- **Elasticity**: Cloud-based applications can be configured to always have the resources they need.
- **Agility**: Cloud-based resources can be deployed and configured quickly as your application requirements change.
- **Geo-distribution**: Applications and data can be deployed to regional datacenters around the globe, so your customers always have the best performance in their region.
- **Disaster recovery**: By taking advantage of cloud-based backup services, data replication, and geo-distribution, you can deploy your applications with the confidence that comes from knowing that your data is safe in the event that disaster should occur.

## Cloud service models

- **Infrastructure as a service (IaaS)**: A cloud provider keeps the hardware up to date, but operating system maintenance and network configuration is left to the cloud tenant.
- **Platform as a service (PaaS)**: The cloud provider manages the virtual machines and networking resources, and the cloud tenant deploys their applications into the managed hosting environment.
- **Software as a service (SaaS)**: The cloud provider manages all aspects of the application environment, such as virtual machines, networking resources, data storage, and applications. The cloud tenant only needs to provide their data to the application managed by the cloud provider.

![https://docs.microsoft.com/en-us/learn/azure-fundamentals/intro-to-azure-fundamentals/media/iaas-paas-saas.png](https://docs.microsoft.com/en-us/learn/azure-fundamentals/intro-to-azure-fundamentals/media/iaas-paas-saas.png)

Illustration that shows the services separated by cloud service models.

![https://docs.microsoft.com/en-us/learn/azure-fundamentals/intro-to-azure-fundamentals/media/shared-responsibility.png](https://docs.microsoft.com/en-us/learn/azure-fundamentals/intro-to-azure-fundamentals/media/shared-responsibility.png)

Chart that shows the shared responsibilities for cloud providers and cloud tenants.

## Serverless computing

Overlapping with PaaS, serverless computing enables developers to build applications faster by eliminating the need for them to manage infrastructure. In understanding the definition of serverless computing, it’s important to note that servers are still running the code. The serverless name comes from the fact that the tasks associated with infrastructure provisioning and management are invisible to the developer.

## Public, private, and hybrid clouds

- **Public cloud**: Services are offered over the public internet and available to anyone who wants to purchase them. Cloud resources like servers and storage are owned and operated by a third-party cloud service provider and delivered over the internet.
- **Private cloud**: Computing resources are used exclusively by users from one business or organization. A private cloud can be physically located at your organization’s on-site datacenter. It also can be hosted by a third-party service provider.
- **Hybrid cloud**: This computing environment combines a public cloud and a private cloud by allowing data and applications to be shared between them.

## Virtualization

- **Virtual Machine**: provides an environment that is logically separated from the underlying hardware.
- **Hypervisor**: emulates all the functions of a real computer, and a cpu and a virtual machine. Run multiple virtual machines.
- **Servers**: The hardware. Can be spread throughout the world. Each server has an hypervisor and to run multiple virtual machines.
- **Network Switch**: Provides connectivity to all of the servers.
- **Fabric Controller**: A software that controls the server. Each is connected to the Orchestrator.
- **Orchestrator**: Responsible for managing everything that happens in Azure, including responding to user request.
- **API**: What the users use to make requests to the orchestrator. Can be called by many tools, including the user interface of the cloud service provider (such as Azure Portal or AWS portal).
