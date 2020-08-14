## ---- setup, echo = F---------------------------------------------------------
knitr::opts_chunk$set(fig.width = 6, fig.height = 6, eval = FALSE, echo =  TRUE)

## ---- echo = F----------------------------------------------------------------
#  set.seed(2020)

## -----------------------------------------------------------------------------
#  library("devtools")
#  devtools::install_github("rvpanaro/bsem", dependencies = TRUE)

## -----------------------------------------------------------------------------
#  install.packages("bsem", dependencies = TRUE)

## -----------------------------------------------------------------------------
#  sem(
#    data,
#    blocks,
#    paths,
#    exogenous,
#    signals,
#    row_names = rownames(data),
#    prior_specs = list(
#      beta = c("normal(0,1)"),
#      sigma2 = c("inv_gamma(2.1, 1.1)"),
#      gamma0 = c("normal(0,1)"), gamma = c("normal(0,1)"),
#      tau2 = c("inv_gamma(2.1, 1.1)")
#    ),
#    cores = parallel::detectCores(),
#    pars = c("alpha", "lambda", "sigma2"),
#    iter = 2000,
#    chains = 4,
#    scaled = FALSE,
#    ...
#  )

## ---- eval = TRUE-------------------------------------------------------------
dt <- bsem::simdata()
names(dt)

## ---- eval = TRUE-------------------------------------------------------------
dt$exogenous

## ---- eval = TRUE-------------------------------------------------------------
dt$blocks

## ---- eval = TRUE-------------------------------------------------------------
colnames(dt$data)

## -----------------------------------------------------------------------------
#  fit <- bsem::sem(
#    data = dt$data,
#    blocks = dt$blocks,
#    paths = dt$paths,
#    exogenous = dt$exogenous,
#    signals = dt$signals
#    )
#  
#  fit

## -----------------------------------------------------------------------------
#  plot(fit)

## -----------------------------------------------------------------------------
#  gridExtra::grid.arrange(
#    bsem::arrayplot(fit$mean_lambda, main = "estimates"),
#    bsem::arrayplot(dt$real$lambda, main = "lambda (scores)")
#  )
#  
#  gridExtra::grid.arrange(
#    bsem::arrayplot(fit$mean_alpha, main = "estimates"),
#    bsem::arrayplot(dt$real$alpha, main = "alpha (loadings)"),
#    layout_matrix = matrix(c(1,1,2,2), ncol  = 2)
#  )

## -----------------------------------------------------------------------------
#  summary(fit)

